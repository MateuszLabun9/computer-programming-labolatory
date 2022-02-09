#ifndef _PROJECTILE_H
#define _PROJECTILE_H
#include "ProjectileCollection.h"
#include "Vector2D.h"
#include <iostream>
class ProjectileCollection;
class Projectile
{
protected:
	Vector2D pozycja_pocisku;
	Vector2D kierunek_ruchu_pocisku;
	float predkosc = 0;
	string nazwa_pocisku;
public:
	virtual void Display()
	{
		std::cout << "pozycja" << pozycja_pocisku.x << pozycja_pocisku.y;
		std::cout << "kierunek" << kierunek_ruchu_pocisku.x << kierunek_ruchu_pocisku.y;
		std::cout << "predkosc" << predkosc;
		std::cout << "metoda print klasy Projectile\n";
	}
	virtual void Frame(ProjectileCollection& projectiles) = 0;
	//{
	//	std::cout << "metoda action klasy Projectile\n";
	//}
	void shift() {

		pozycja_pocisku += kierunek_ruchu_pocisku * predkosc;

	}

	Projectile(const Vector2D& pozycja, const Vector2D& kierunek, float predkosc, const string& nazwa_pocisku) : pozycja_pocisku(pozycja), kierunek_ruchu_pocisku(kierunek), predkosc(predkosc), nazwa_pocisku(nazwa_pocisku) {
		kierunek_ruchu_pocisku.normalize();
	}




};

class ClusterBomb :public Projectile
{

	int licznik;
	ClusterBomb(const Vector2D& pozycja, const Vector2D& kierunek) : Projectile(pozycja, kierunek, 2, "ClusterBomb"), licznik(5) {};


};

class ShotgunShell :public Projectile
{

	ShotgunShell(const Vector2D& pozycja, const Vector2D& kierunek) : Projectile(pozycja, kierunek, 50, "ShotgunShell") {};

};

class Cluster :public Projectile
{

	Cluster(const Vector2D& pozycja, const Vector2D& kierunek) : Projectile(pozycja, kierunek, 100, "Cluster") {};

};





#endif