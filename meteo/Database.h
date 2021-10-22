//*********************************************************************************************
//* Programme : Database.h											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* dernière mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : Créer une connexion à la base de donnée et enregistrer des données dans celle-ci
//*Programmes associés : Database.cpp
//*********************************************************************************************
#pragma once

#include <QObject>
#include <QtSql/QtSql>
#include <qsqldatabase.h>
#include <QDebug>

class Database : public QObject
{
	Q_OBJECT

private:
	QSqlDatabase * db;
public:
	Database(QObject *parent = Q_NULLPTR);
	~Database();
	void connectToDB();
	void insertInDB(double temperature, double tension);
};
