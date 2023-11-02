#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include "dtransferencia.h"
#include "DPrincipal.h"
	
DPrincipal::DPrincipal(QWidget * parent ) : QDialog(parent) {

    QHBoxLayout *lyPrincipal = new QHBoxLayout();
    bLanzar = new QPushButton("Lanzar Transferencia");
    etiqResultado = new QLabel("ESTE ES EL TEXTO INISIAL DE LA HETI KETA");
    lyPrincipal->addWidget(bLanzar);
    lyPrincipal->addWidget(etiqResultado);
    setLayout(lyPrincipal);
	
	connect(bLanzar,SIGNAL(clicked()),this,
   			 SLOT(slotLanzarDialogoTransferencia()));

	dTransferencia = NULL;
    setLayout(lyPrincipal);

}
	
	
	void DPrincipal::slotLanzarDialogoTransferencia(){

    if ( dTransferencia == NULL){
		 dTransferencia = new DTransferencia();
		 
		 connect(dTransferencia,SIGNAL(accepted()),
			this,SLOT(slotTransferenciaAceptada()));
		 
		 connect(dTransferencia,SIGNAL(rejected()),
			this,SLOT(slotTransferenciaRechazada()));
			
		//connect(dTransferencia->leCantidad,SIGNAL(textChanged());
	}
    dTransferencia->show();

	}

	void DPrincipal::slotTransferenciaAceptada(){
		//etiqResultado->setText("Transferencia aceptada");
		QString texto = dTransferencia->lComision->text();
		etiqResultado->setText(texto);
		}
		
	void DPrincipal::slotTransferenciaRechazada(){
		etiqResultado->setText("Transferencia rechazada");
		}




