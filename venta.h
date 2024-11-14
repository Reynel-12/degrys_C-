#ifndef VENTA_H
#define VENTA_H

#include <QMainWindow>
#include "vend.h"
#include "factura.h"

#include "databaseproductos.h"
#include "agregarinventario.h"
#include "numinventario.h"
#include "contra.h"
#include "opcionproductos.h"
#include "nuevoproducto.h"
#include "modificarprod.h"
#include "modifi.h"
#include "cambiarnombre.h"
#include "cambiarunidad.h"
#include "cambiarprecio.h"
#include "eliminarproducto.h"
#include <QTableView>
#include <QDialog>
#include <QTimer>

#include <QTcpServer>
#include <QTcpSocket>
#include <QHostAddress>

#include <QMap>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QSqlError>
#include <QTextTable>
#include <QTextCharFormat>
#include <functional>

namespace Ui {
class Venta;
}

class QSqlQueryModel;

class Venta : public QMainWindow
{
    Q_OBJECT

public:
    explicit Venta(QWidget *parent = nullptr);

    ~Venta();
    void cargarUltimoNumeroFactura();
    void guardarUltimoNumeroFactura();
    void guardarDatos();
    void listening();
    QString ProcesarProducto(QString);
    void guardarDatosCaja1();
    void guardarDatosCaja2();
    void crearPDF(QTableView* tabla, const QString &filePath);
    void borrarContenidoArchivo(const QString &filename);
    void procesarCredito(const QString &codCliente);
    void procesarVenta();
    void showWarning(const QString &message);
    bool verificarContrasena(const QString& Contrasena);
    QString obtenerOpcionProducto();
    void leerContrasenaDesdeArchivo();
    void agregar_Inventario();
    QString obtenerCodigoProducto();
    using ProductoCallback = std::function<void(const QString&)>;
    void obtenerInformacionProducto(const QString &cod, ProductoCallback callback);
    int obtenerInventarioAdicional();
    bool actualizarInventario(const QString &cod, int inventarioAdicional);
    void agregarNuevoProducto();
    bool verificarCodigoProductoExistente(const QString &codigo);
    void modificarProducto();
    void cambiarCodigoProducto();
    void cambiarNombreProducto();
    void cambiarUnidadProducto();
    void cambiarPrecioProducto();
    void eliminarProducto();
    void borrarFacturas();
    void guardarNumeroFactura();
    void agregar_Cliente();
    void showInformation(const QString &message);
    void configurarEncabezados(QStandardItemModel *model);
    void llenarModelo(QStandardItemModel *model);
    void llenarProductos();
    void conectarSeleccionFila();
    void actualizarDetallesProducto(const QModelIndex &current, const QModelIndex &);
    void agregarEncabezadosTabla(QTextTable *table, const QTextCharFormat &boldFormat);
    void agregarProductosATabla(QTextTable *table);
    void procesarCodigoDeBarras();
    void setLineEditsReadOnly(const QList<QLineEdit*>& lineEdits);
    void setLineEditsValidator(const QList<QLineEdit*>& lineEdits, const QRegularExpression& regExp);
    void applyButtonStyles();
    void applyLineEditStyles();
    void applyTableStyles();
    void hideSecondaryElements();
    void onRowSelected(const QModelIndex &current);
    QString IP = "127.0.0.1";
    void opcionesProductos(const QString& msg);
    void onContrasenaObtenida(const QString& contraseñaArchivo);
    //void borrarProductoCaja(QTableWidget *tableWidget, QLineEdit *totalLineEdit, QVector<int> &filaCaja, QVector<double> &prCaja, const QString &cajaNombre);

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

public slots:
    void Abrir();
    void Anadir();
    void Limpiar();
    void Vender();
    void Historial();
    void ImprimeFac();
    void BuscarEnTabla(const QString &texto, QTableView* tabla);
    void BuscarCodProd();
    void RecibirCambioCliente(const QVector<Factura> &datos);
    void anadirInventario();
    void Iniciar();
    void Apagar();
    void NuevaConexion();
    QString RecibiendoMensajes();
    void ClienteDesconectado(QString clientId, QTcpSocket *socket);
    void GenerarReporte();
    void AgregarDescuento();
    void VerClientes();
    void Mas();
    void inventarioOptimo();

private slots:
    void on_EliminarProd_clicked();
    void actualizarTotal(double subtotalFila);
    void resetBarcodeData();
    void on_pbtBorrarProdCaja1_clicked();
    void on_pbtBorrarProdCaja2_clicked();

    //void on_pushButton_clicked();

    void on_pbtConfigIP_clicked();

private:
    Ui::Venta *ui;
    QVector<double> pr;
    QVector<Vend> VN;
    QVector<int> FAC;
    QVector<int> Fila;
    QVector<Factura> Fac;
    QVector<int> FilaInvert;
    QVector<Factura> CamCli;
    static int ultimoNumeroFactura;
    int fac;
    QVector<Vend> copiaFac;
    QTimer *timer;
    enum ColFac
    {
        CODFAC, PRODFAC, TIPOFAC, CANTFAC, PRECIOFAC, SUBFAC, DESCUENTOFAC
    };
    databaseproductos mDbConnection;
    QSqlQueryModel *mModel;
    QList<QTcpSocket *> connects;
    QTcpServer * server;
    QList<QStringList> mProductos;
    QMap<QTcpSocket*, QString> socketClientIdMap;
    QMap<QString, QTableWidget*> tablasClientes;
    QVector<double> prCaja1;
    QVector<int> FilaCaja1;
    QVector<int> FilaInvertCaja1;
    QVector<double> prCaja2;
    QVector<int> FilaCaja2;
    QVector<int> FilaInvertCaja2;
    QVector<Vend> VNCaja1;
    QVector<Vend> VNCaja2;
    QVector<Vend> copiaFacCaja1;
    QVector<Vend> copiaFacCaja2;
    QString getClientIdForSocket(QTcpSocket *socket);
    QString barcodeData;
    QTimer *resetTimer;
    QString descuentoActual = "0";

signals:
    void contrasenaObtenida(const QString& contraseña);  // Declaración de la señal
};

#endif // VENTA_H
