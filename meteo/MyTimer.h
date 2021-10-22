//*********************************************************************************************
//* Programme : MyTimer.h											date : 19/10/2021
//*---------------------------------------------------------------------------------------------------------
//* derni�re mise a jour : 22/10/2021
//*
//*Programmeurs : BERTHIER Thomas										classe : BTSSN2
//*				  VOLLET Maxence
//*				  DE ALMEIDA Nicolas
//*--------------------------------------------------------------------------------------------------------
//* BUT : R�cuperer a intervalle r�guliers la tension et temp�rature d'une sonde PT100
//*Programmes associ�s : MyTimer.cpp
//*********************************************************************************************
#pragma once

#include <QObject>
#include <QTimer>
#include <windows.h>
#include <qdebug.h>
#include "K8055Adapter.h"
#include "Database.h"

class MyTimer : public QObject
{
	Q_OBJECT

private:
	Database * db;
	K8055Adapter * carteES;
public:
	MyTimer(QObject *parent, Database * db);
	~MyTimer();
	QTimer * FiveSecTimer;
	QTimer * FiveMinTimer;

public slots:
	void onTimeoutSec();
	void onTimeoutMin();
};