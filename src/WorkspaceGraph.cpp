#include <Workspace.h>
#include <WorkspacePrivate.h>

#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>

typedef boost::adjacency_list<boost::setS, boost::vecS, boost::directedS> Graph;

struct CircleDetector : boost::default_dfs_visitor
{
    bool &hasCircle;

    CircleDetector(bool &value) : hasCircle(value)
    { }

    template <class Edge, class Graph>
    void back_edge(Edge, const Graph &)
    { hasCircle = true; }
};

bool Workspace::hasCircle() const
{
    Graph g(d->edges.begin(), d->edges.end(), 4);

    bool v;
    CircleDetector vis(v);
    boost::depth_first_search(g, visitor(vis));
    return v;
}
