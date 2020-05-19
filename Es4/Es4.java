import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Es4 {

  public static Scanner openFile(String path)
  {
    Scanner input = null;
    try
    {
      input = new Scanner(new File(path));
    } catch (FileNotFoundException e) {
      System.out.println("Error in openFile:\npathname "+path);
      System.exit(0);
    } 
    return input;
  }

  public static void loadFile(Scanner input, Graph<Integer> graph, ArrayList<Query> queries)
  {
    Integer nodesNumber = input.nextInt();
    graph.setNodesNumber(nodesNumber);

    //load graph nodes
    for(int i = 0; i < nodesNumber - 1; i++)
    {
      Integer num;
      Node<Integer> first, second;
      //System.out.println(graph.nodes.size());

      num = input.nextInt();
      if((first = graph.get(num)) == null)
      {
        first = graph.add(num);
      }

      num = input.nextInt();
      if((second = graph.get(num)) == null)
        second = graph.add(num);

      num = input.nextInt();
      first.addAdjacency(second, num);
      second.addAdjacency(first, num);
    }

    //load queries
    Integer queryNumber = input.nextInt();
    for(int i = 0; i < queryNumber; i++)
    {
      Node node1 = graph.get(input.nextInt());
      Node node2 = graph.get(input.nextInt());
      int weight = input.nextInt();
      queries.add(new Query(node1, node2, weight));
    }
  }


  public static void main(String[] args)
  {
    Graph<Integer> graph = new Graph<>();
    ArrayList<Query> queries = new ArrayList<>();
    loadFile(openFile(args[0]), graph, queries);
    //graph.dfs(graph.get(1), 0, null);
    graph.dfs(graph.get(1), new Stack<>());
    System.out.println("dfs completed");

    for(Query q : queries)
    {
        //System.out.println(q.execute(graph));
        q.execute(graph);
    }


  }


}

class Graph<T> {
  HashMap<T, Node<T>> nodes;

  public void setNodesNumber(int nodesNumber)
  {
    nodes = new HashMap<>(100000);
  }

  public Node<T> add(T data)
  {
    Node<T> node = new Node<>(data);
    nodes.put(data, node);
    return node;
  }

  public int size()
  {
    return nodes.size();
  }

  public Node<T> get(int position)
  {
    return nodes.get(position);
  }

/*  public void dfs(Node<T> start, int level, Adjacent<T> parent)
  {
    start.visited = true;
    start.level = level;
    start.parent = parent;

    for(Adjacent<T> adj : start.adjacency)
    {
        if(!adj.node.visited)
        {
            dfs(adj.node, level + 1, new Adjacent<>(start, adj.weight));
        }
    }
  }*/

  public void dfs(Node<T> start, Stack<Node<T>> stack)
  {
      start.level = 0;
      start.visited = true;
      start.parent = null;
      stack.push(start);

      while(!stack.empty())
      {
          Node<T> current = stack.pop();
          for(Adjacent<T> adj : current.adjacency)
          {
              if(!adj.node.visited)
              {
                  adj.node.visited = true;
                  adj.node.level = current.level + 1;
                  adj.node.parent = new Adjacent<>(current, adj.weight);
                  stack.push(adj.node);
              }
          }
      }
  }
  @Override
  public String toString()
  {
    String result = "";
    Iterator<Node<T>> it = nodes.values().iterator();
    while(it.hasNext())
    {
      result += it.next().toString();
    }
    return result;
  }
}

class Node<T> {
  public T data;
  public ArrayList<Adjacent<T>> adjacency;
  public boolean visited;
  Adjacent<T> parent;
  int level;

  public Node(T data)
  {
    this.data = data;
    adjacency = new ArrayList<>();
    visited = false;
    parent = null;
    level = -1;
  }

  public void addAdjacency(Node<T> node, int weight)
  {
    adjacency.add(new Adjacent<>(node, weight));
  }

  @Override
  public String toString()
  {
    String result = "\nNode{" + "data=" + data;
    Iterator<Adjacent<T>> it = adjacency.iterator();

    while (it.hasNext())
    {
      Adjacent<T> adj = it.next();
      result +=  "  adj: ";
      result += ((adj != null && adj.node != null) ? adj.node.data + ",  " + adj.weight + "." : null);
    }

    result += '}';
    return result;
  }
}

class Adjacent<T> {
  Node<T> node;
  int weight;

  public Adjacent(Node<T> node, int weight)
  {
    this.node = node;
    this.weight = weight;
  }
}

class Query<T> {
  Node node1;
  Node node2;
  int weight;

  public Query(Node node1, Node node2, int weight)
  {
    this.node1 = node1;
    this.node2 = node2;
    this.weight = weight;
  }

  String execute(Graph<T> graph)
  {
      Node<T> n1 = node1;
      Node<T> n2 = node2;
      boolean cont = false;

      while(n1 != n2)
      {
          while(n1.level > n2.level || cont)
          {
              if(n1.parent.weight > this.weight)
                  return "YES";
              n1 = n1.parent.node;
              if(cont)
                cont = false;
          }
          while(n2.level > n1.level)
          {
              if(n2.parent.weight > this.weight)
                  return "YES";
              n2 = n2.parent.node;
          }
          if(n1.level == n2.level)
              cont = true;
      }
      return "NO";
  }

  @Override
  public String toString() {
    return "Query{" +
            "node1=" + node1.data +
            ", node2=" + node2.data +
            ", weigth=" + weight +
            '}';
  }
}