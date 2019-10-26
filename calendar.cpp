#include "calendar.h"
#include <QPainter>

Calendar::Calendar(QWidget *parent) :
    QCalendarWidget(parent)
{
    //m_currentDate = QDate::currentDate();
    m_outlinePen.setColor(Qt::red);
    m_transparentBrush.setColor(Qt::transparent);
}

Calendar::~Calendar()
{
}

void Calendar::setColor(QColor& color)
{
   m_outlinePen.setColor(color);
}

void Calendar::setStartOfRent(QDate &date)
{
   rent_start = QDate(date);
}

void Calendar::setEndOfRent(QDate &date)
{
   rent_end = QDate(date);
}


QColor Calendar::getColor()
{
   return (m_outlinePen.color());
}

void Calendar::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
   QCalendarWidget::paintCell(painter, rect, date);

    if(date >= rent_start && date <= rent_end)
    {
       painter->setPen(m_outlinePen);
       painter->setBrush(m_transparentBrush);
       painter->drawRect(rect.adjusted(0, 0, -1, -1));
    }
}

void Calendar::paintCells()
{
    QDate date;
    for(date = rent_start; date != rent_end; date.addDays(1))
    {

    }
}
