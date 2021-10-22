//*********************************************************************************************
//* Programme : main.cpp											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : Instancie la base de donnée et les timers et lance l'apllication
//*Programmes associés : AUCUN
//*********************************************************************************************
#include <QtCore/QCoreApplication>
#include "K8055Adapter.h"
#include "Database.h"
#include "MyTimer.h"
#include <qdebug.h>
#include <qthread.h>

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Database * db = new Database;

	MyTimer timer(&a, db);

	return a.exec();
}
