#ifndef DPRINCIPAL_H
#define DPRINCIPAL_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include "dtransferencia.h"


class DPrincipal : public QDialog {
Q_OBJECT
public:
  DPrincipal(QWidget * parent = 0) ;

  DTransferencia *dTransferencia; 
  QPushButton *bLanzar;
  QLabel *etiqResultado;

public slots:
  void slotLanzarDialogoTransferencia();
  void slotTransferenciaAceptada();
  void slotTransferenciaRechazada();
};
#endif
