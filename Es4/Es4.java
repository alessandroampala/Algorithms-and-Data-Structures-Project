import java.util.HashMap;
import java.util.Iterator;
import java.util.Scanner;
import java.util.ArrayList;
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

    /*System.out.println("Graph");
    System.out.println(graph);

    System.out.println("Queries");
    Iterator<Query> it = queries.iterator();
    while(it.hasNext())
    {
      System.out.println(it.next());
    }*/
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
  ArrayList<Adjacent<T>> adjacency;
  ArrayList<Node<T>> reachable;

  public Node(T data)
  {
    this.data = data;
    adjacency = new ArrayList<>();
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

    result += " reachable=" + reachable + '}';
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

class Query {
  Node node1;
  Node node2;
  int weigth;

  public Query(Node node1, Node node2, int weigth)
  {
    this.node1 = node1;
    this.node2 = node2;
    this.weigth = weigth;
  }

  @Override
  public String toString() {
    return "Query{" +
            "node1=" + node1.data +
            ", node2=" + node2.data +
            ", weigth=" + weigth +
            '}';
  }
}