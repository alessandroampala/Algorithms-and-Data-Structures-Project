import java.util.HashMap;
import java.util.Stack;

public class Graph {
    HashMap<Integer, Node> nodes;

    public void setNodesNumber(int nodesNumber)
    {
        nodes = new HashMap<>(100000);
    }

    public Node add(Integer data)
    {
        Node node = new Node(data);
        nodes.put(data, node);
        return node;
    }

    public int size()
    {
        return nodes.size();
    }

    public Node get(int position)
    {
        return nodes.get(position);
    }

    public void dfs(Node start, Stack<Node> stack)
    {
        start.level = 0;
        start.visited = true;
        start.parent = null;
        stack.push(start);

        while(!stack.empty())
        {
            Node current = stack.pop();
            for(Adjacent adj : current.adjacency)
            {
                if(!adj.node.visited)
                {
                    adj.node.visited = true;
                    adj.node.level = current.level + 1;
                    adj.node.parent = new Adjacent(current, adj.weight);
                    stack.push(adj.node);
                }
            }
           //current.adjacency = null;
        }
    }
    @Override
    public String toString()
    {
        StringBuilder result = new StringBuilder();
        for (Node node : nodes.values())
        {
            result.append(node.toString());
        }
        return result.toString();
    }
}