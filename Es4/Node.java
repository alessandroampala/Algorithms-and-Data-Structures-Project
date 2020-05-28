import java.util.ArrayList;
import java.util.Iterator;

public class Node {
  public int data;
  public ArrayList<Adjacent> adjacency = new ArrayList<>();
  public boolean visited = false;
  Adjacent parent = null;
  int level = -1;

  public Node(int data)
  {
    this.data = data;
  }

  public void addAdjacency(Node node, int weight)
  {
    adjacency.add(new Adjacent(node, weight));
  }

  @Override
  public String toString()
  {
    String result = "\nNode{" + "data=" + data;
    Iterator<Adjacent> it = adjacency.iterator();

    while (it.hasNext())
    {
      Adjacent adj = it.next();
      result +=  "  adj: ";
      result += ((adj != null && adj.node != null) ? adj.node.data + ",  " + adj.weight + "." : null);
    }

    result += '}';
    return result;
  }
}
