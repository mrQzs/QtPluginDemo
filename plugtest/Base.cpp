#include "Base.h"

Base::Base() : m_widget{nullptr} {}

Base::~Base() {}

QString Base::name() const { return m_name; }

QWidget *Base::editor() const { return m_widget; }

void Base::setName(const QString &str) { m_name = str; }

void Base::setWidget(QWidget *w) { m_widget = w; }
