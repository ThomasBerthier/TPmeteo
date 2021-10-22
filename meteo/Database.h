//*********************************************************************************************
//* Programme : Database.h											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : Cr�er une connexion � la base de donn�e et enregistrer des donn�es dans celle-ci
//*Programmes associ�s : Database.cpp
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
