class Query {
    Node node1;
    Node node2;
    int weight;

    public Query(Node node1, Node node2, int weight)
    {
        this.node1 = node1;
        this.node2 = node2;
        this.weight = weight;
    }

    String execute()
    {
        Node n1 = node1;
        Node n2 = node2;
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