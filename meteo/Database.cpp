//*********************************************************************************************
//* Programme : Database.cpp											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : Créer une connexion à la base de donnée et enregistrer des données dans celle-ci
//*Programmes associés : main.cpp, MyTimer.cpp
//*********************************************************************************************
#include "Database.h"


Database::Database(QObject *parent)
	: QObject(parent)
{
}

Database::~Database()
{
}
//Connexion BDD
void Database::connectToDB()
{
	QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
	db.setHostName("192.168.64.113");
	db.setDatabaseName("station_meteo");
	db.setUserName("meteo");
	db.setPassword("meteo");

	if (db.open()) {
		qDebug() << "Connexion BDD reussie";
	}
	else {
		qDebug() << "Erreur connexion BDD";
		exit(1);
	}
}
//Insertion BDD prenant en paramètres la temperature et la tension
void Database::insertInDB(double temperature, double tension)
{
	QSqlQuery request;
	request.prepare("INSERT INTO `temperature`(`temperature`, `tension`) VALUES(?, ?)");
	request.addBindValue(temperature);
	request.addBindValue(tension);

	request.exec();
}