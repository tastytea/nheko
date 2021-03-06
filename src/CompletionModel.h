#pragma once

// Class for showing a limited amount of completions at a time

#include <QSortFilterProxyModel>

class CompletionModel : public QSortFilterProxyModel
{
public:
        CompletionModel(QAbstractItemModel *model, QObject *parent = nullptr)
          : QSortFilterProxyModel(parent)
        {
                setSourceModel(model);
        }
        int rowCount(const QModelIndex &parent) const override
        {
                auto row_count = QSortFilterProxyModel::rowCount(parent);
                return (row_count < 7) ? row_count : 7;
        }
};
