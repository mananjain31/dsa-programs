import java.util.*;
class trieImplementation
{
    public static void main(String[] args) 
    {
        Trie trie = new Trie();  
        Scanner sc = new Scanner(System.in);
        String s;
        int choice = 0;
        do
        {
            System.out.println(">>>>>>>> TRIE <<<<<<<<<");
            System.out.println("0. Exit");
            System.out.println("1. Insert String");
            System.out.println("2. Delete String");
            System.out.println("3. Count occurence");
            System.out.print("Enter Your Choice : ");
            choice = sc.nextInt();
            sc.nextLine();
            switch(choice)
            {
                case 1:
                    System.out.println("Enter String To Insert : ");
                    s = sc.nextLine();
                    trie.insert(s);
                    System.out.println("Inserted " + s + " Succesfully");
                    break;
                case 2:
                    System.out.println("Enter String To Delete : ");
                    s = sc.nextLine();
                    trie.delete(s);
                    System.out.println("Deleted " + s + " Succesfully");
                    break;
                case 3:
                    System.out.println("Enter String To Count Its Occurence : ");
                    s = sc.nextLine();
                    System.out.println("occurence of " + s + " in the trie is  => " + trie.count(s));
                    break;
            }
        }while(choice != 0);
    }
}
class Trie
{
    Node root;

    Trie()
    {
        root = new Node();
    }

    int count(String s)
    {
        Node curr = root;
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            curr = curr.next(c);
            if(curr == null)
                return 0;
        }
        return curr.terminating;
    }

    void insert(String s)
    {
        Node curr = root;
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(curr.next(c) == null)
                curr.create(c);                
            curr = curr.next(c);
        }
        curr.terminating++;
    }
    void delete(String s)
    {
        Node curr = root;
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            curr = curr.next(c);
            if(curr == null)
                throw new RuntimeException("String not found");
        }
        if(curr.terminating == 0)
            throw new RuntimeException("String not found");
        curr.terminating--;
    }
}

class Node
{
    Node nodes[] = new Node[26];
    int children;
    int terminating;
    Node next(char c)
    {
        return nodes[c-'a'];
    }
    void create(char c)
    {
        nodes[c-'a'] = new Node();
        children++;
    }
}