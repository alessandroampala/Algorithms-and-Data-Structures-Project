import java.util.*;
import java.io.File;
import java.io.FileNotFoundException;

public class Es4 {

  public static void loadFile(Scanner input, Graph graph, ArrayList<Query> queries)
  {
    int nodesNumber = input.nextInt();
    graph.setNodesNumber(nodesNumber);

    //load graph nodes
    for(int i = 0; i < nodesNumber - 1; i++)
    {
      int num;
      Node first, second;

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
    int queryNumber = input.nextInt();
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
    Graph graph = new Graph();
    ArrayList<Query> queries = new ArrayList<>();
    loadFile(new Scanner(System.in), graph, queries);
    //graph.dfs(graph.get(1), 0, null);
    graph.dfs(graph.get(1), new Stack<>());

    for(Query q : queries)
      System.out.println(q.execute());
  }
}
