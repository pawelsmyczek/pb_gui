#ifndef CALENDAR_H
#define CALENDAR_H

#include <QCalendarWidget>
#include <QColor>
#include <QDate>
#include <QPen>
#include <QBrush>


class Calendar : public QCalendarWidget
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ getColor WRITE setColor)
public:
    explicit Calendar(QWidget *parent = nullptr);
    ~Calendar();

    void setColor(QColor& color);
    QColor getColor();

    void setStartOfRent(QDate& date);
    void setEndOfRent(QDate& date);
    void paintCells();
protected:
   virtual void paintCell(QPainter *painter, const QRect &rect, const QDate &date) const;

private:
   QDate rent_start;
   QDate rent_end;
   QPen m_outlinePen;
   QBrush m_transparentBrush;
};

#endif // CALENDAR_H
