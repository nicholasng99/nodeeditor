#pragma once

#include <QFileInfo>

#include "BasicGraphicsScene.hpp"
#include "DataFlowGraphModel.hpp"
#include "Export.hpp"

namespace QtNodes {

/// @brief An advanced scene working with data-propagating graphs.
/**
 * The class represents a scene that existed in v2.x but built wit the
 * new model-view approach in mind.
 */
class NODE_EDITOR_PUBLIC DataFlowGraphicsScene : public BasicGraphicsScene
{
    Q_OBJECT
public:
    DataFlowGraphicsScene(DataFlowGraphModel &graphModel, QObject *parent = nullptr);
    ~DataFlowGraphicsScene() = default;
    std::vector<NodeId> selectedNodes() const;
    QMenu *createSceneMenu(QPointF const scenePos) override;
    QFileInfo getFile() const { return _file; }
    bool isEmpty() const { return _graphModel.isEmpty(); }
    bool isBlank() const { return _graphModel.isEmpty(); }

public Q_SLOTS:
    bool save() const;
    bool saveAs() const;
    bool load();

Q_SIGNALS:
    void sceneLoaded();

private:
    bool writeToFile() const;

    mutable QFileInfo _file;
    DataFlowGraphModel &_graphModel;
};

} // namespace QtNodes
