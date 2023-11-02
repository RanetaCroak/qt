#include "dtransferencia.h"
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

#include <QDebug>

DTransferencia::DTransferencia(QWidget * parent) : QDialog(parent) {

 lyDer = new QVBoxLayout;
 lyIzq = new QVBoxLayout;
 lyPrincipal = new     QHBoxLayout;
 
 lyDestino = new     QHBoxLayout;
 lyCantidad = new     QHBoxLayout;
/* Componentes */
 bAceptar = new QPushButton("Aceptar");
 bAceptar->setEnabled(true);
 
 bCancelar = new QPushButton("Cancelar");
 lDestino = new QLabel("Cuenta destino:");
 lCantidad = new QLabel ("Cantidad");
 lComision = new QLabel ("Comisión 0 euros");

    leDestino = new QLineEdit;
    leCantidad = new QLineEdit;

 lyDer->addWidget(bAceptar);
 lyDer->addWidget(bCancelar);
 lyDer->addStretch();
 
 lyDestino->addWidget(lDestino);
 lyDestino->addWidget(leDestino);
 
 lyCantidad->addWidget(lCantidad);
 lyCantidad->addWidget(leCantidad);
 
 lyIzq->addLayout(lyDestino);
 lyIzq->addLayout(lyCantidad);
 lyIzq->addWidget(lComision);
 lyIzq->addStretch();

 lyPrincipal->addLayout(lyIzq);
 lyPrincipal->addLayout(lyDer);
 
    setLayout(lyPrincipal);

	connect(leDestino,SIGNAL(textChanged(const QString &)),
   	 this, SLOT(slotActualizarBoton(const QString &)));
    
	connect(leCantidad,SIGNAL(textChanged(const QString &)),
   	 this, SLOT(slotActualizarBoton(const QString &)));
   	 
	connect(leCantidad,SIGNAL(textChanged(const QString &)),
   	 this, SLOT(slotActualizarComision(const QString &)));

	connect( bAceptar  , SIGNAL (clicked() ),
   	 this , SLOT( accept()));
   	 
	connect( bCancelar  , SIGNAL (clicked() ),
   	 this , SLOT( reject()));
   	 
   	
   	
    resize(400,100);
}


void DTransferencia::slotActualizarBoton(const QString & cad){
 
    QString cadDestino = leDestino->text();
    QRegularExpression reDestino("^\\d{6}$");

    QRegularExpressionMatch mDestino = reDestino.match(cadDestino);
    
    
    QString cadCantidad = leCantidad->text();
    QRegularExpression reCantidad("^\\d+$");

    QRegularExpressionMatch mCantidad = reCantidad.match(cadCantidad);

    bool destinoOK = mDestino.hasMatch();
    bool cantidadOK = mCantidad.hasMatch();
    
    if (destinoOK && cantidadOK)
   	 bAceptar->setEnabled(true);
    else
   	 bAceptar->setEnabled(false);
    qDebug() << "slotActualizarBoton ejecutándose " << cad;
}

void DTransferencia::slotActualizarComision(const QString &cad){

    QString cadena = leCantidad->text();
    float cantidad = cadena.toFloat();
    
    QString resultado("La comision es de ");
    resultado += QString::number(cantidad*0.01);
    resultado += " euros";
    
    lComision->setText(resultado);
    
    
    resultado = "La cantidad es de " + cadena ;

   qDebug() << resultado;
}
