#ifndef DTRANSFERENCIA_H
#define DTRANSFERENCIA_H

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>

class DTransferencia : public QDialog{
	Q_OBJECT
	
	public:
/* layouts */
    QVBoxLayout *lyDer, *lyIzq;
    QHBoxLayout *lyPrincipal, *lyDestino, *lyCantidad;
/* Componentes */
    QPushButton *bAceptar, *bCancelar;
    QLabel *lDestino, *lCantidad, *lComision;
    QLineEdit *leDestino ,  *leCantidad;
    
    DTransferencia(QWidget * parent = 0) ;
		
	
public slots:
   void slotActualizarBoton(const QString &);
   void slotActualizarComision(const QString &);
	};
#endif
