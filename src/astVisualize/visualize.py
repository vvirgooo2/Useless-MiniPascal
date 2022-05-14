import json
from graphviz import Digraph

nodeIndex = 0


def subtree_plot(g, tree, parentIndex):
    global nodeIndex

    nodeKey = list(tree.keys())[0]
    nodeValue = tree[nodeKey]
    if isinstance(nodeValue, list):
        # nonleaf node
        for node in nodeValue:
            nodeIndex += 1
            g.node(str(nodeIndex), list(node.keys())[0])
            g.edge(str(parentIndex), str(nodeIndex))
            subtree_plot(g, node, str(nodeIndex))
    else:
        # leaf node
        nodeIndex += 1
        g.node(str(nodeIndex), nodeValue)
        g.edge(str(parentIndex), str(nodeIndex))


def visualizeAST(jsonFilePath, filename):
    with open(jsonFilePath, 'r') as jsonFile:
        astDict = json.load(jsonFile)

    g = Digraph("G", filename=filename, format='png', strict=False)
    rootLabel = list(astDict.keys())[0]
    g.node(str(nodeIndex), rootLabel)
    subtree_plot(g, astDict, 0)
    g.view(filename=filename)


if __name__ == "__main__":
    jsonFilePath = "./test.json"  # 生成的JSON路径
    figName = "test"  #生成的图片名
    visualizeAST(jsonFilePath, figName)