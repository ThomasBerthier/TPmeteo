//*********************************************************************************************
//* Programme : MyTimer.cpp											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : Récuperer a intervalle réguliers la tension et température d'une sonde PT100
//*Programmes associés : main.cpp
//*********************************************************************************************
#include "MyTimer.h"


MyTimer::MyTimer(QObject *parent, Database * db)
	: QObject(parent)
{
	//Créer un nouveau timer de 5s
	FiveSecTimer = new QTimer(this);
	QObject::connect(FiveSecTimer, SIGNAL(timeout()), this, SLOT(onTimeoutSec()));
	FiveSecTimer->start(5000);

	//Créer un nouveau timer de 5m
	FiveMinTimer = new QTimer(this);
	QObject::connect(FiveMinTimer, SIGNAL(timeout()), this, SLOT(onTimeoutMin()));
	FiveMinTimer->start(305000);

	//Se connecte à la BDD et récupère l'instance de la carte E/S puis ouvre une connexion à celle-ci
	this->db = db;
	db->connectToDB();
	carteES = K8055Adapter::getInstance();
	carteES->OpenDevice(0);

}

MyTimer::~MyTimer()
{
}

//A chaque fin du timer 5s, recupère l'information usr la carte E/S puis calcule la tension et la température avant de l'afficher et de l'envoyer en BDD
void MyTimer::onTimeoutSec()
{
	double numericalValue = carteES->ReadAnalogChannel(1);
	//Transforme la valeur numérique en tension
	double voltageValue = numericalValue / 255.0 * 5.0;
	qDebug() << "La tension est de :" << voltageValue << "V";
	//Transforme la tension en température
	double temperatureValue = (voltageValue * 90 / 5) - 30;
	qDebug() << "La temperature est de :" << temperatureValue << "C";
	qDebug() << "";
	db->insertInDB(temperatureValue, voltageValue);
}

//Lorsque le timer de 5m est terminé, stop les 2 timers, ferme la connexion à la carte E/S puis supprime son instance
void MyTimer::onTimeoutMin()
{
	FiveSecTimer->stop();
	FiveMinTimer->stop();
	carteES->CloseDevice();
	K8055Adapter::freeInstance();
}