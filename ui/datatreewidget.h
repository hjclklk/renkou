#ifndef DATATREEWIDGET_H
#define DATATREEWIDGET_H
#include <QTreeWidget>
#include <QDomDocument>
#include <QHash>
#include <QIcon>
class QPushButton;
class QSignalMapper;
class StudyObject;
class DataTreeWidget
        :public QTreeWidget
{
    Q_OBJECT

public:
    DataTreeWidget(QWidget *parent = 0);

    bool read(QIODevice *device, QString &type, StudyObject *object);
    bool write(QIODevice *device);

private slots:
    void updateDomElement(QTreeWidgetItem *item, int column);
    void importBtnClicked(const QString &string);
private:
    void parseHeaderElement(const QDomElement &element,
                            QTreeWidgetItem *parentItem = 0,
                            int level = 0);
    QTreeWidgetItem *createItem(const QDomElement &element,
                                QTreeWidgetItem *parentItem = 0,
                                int level = 0);

    bool writeTmpFile();

    QDomDocument domDocument;
    QHash<QTreeWidgetItem *, QDomElement> domElementForItem;

    QHash<QString, QTreeWidgetItem*> valueForItem;
    QIcon toImportIcon;
    QIcon ImportedIcon;

    QStringList headLabels;
    QString extensionType;
    const int MAX_LEVEL;
    //const QString importType;
    QSignalMapper *signalMapper;

    StudyObject *object;
};

#endif // DATATREEWIDGET_H
