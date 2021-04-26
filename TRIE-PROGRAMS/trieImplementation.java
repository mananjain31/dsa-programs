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
            System.out.println("4. Update String");
            System.out.println("5. Show All Data");
            System.out.print("Enter Your Choice : ");
            choice = sc.nextInt();
            sc.nextLine();
            try{
	            switch(choice)
	            {
	            	case 0:
	            		break;
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
	                case 4:
	                    System.out.println("Enter String to update its value :");
	                    String oldStr = sc.nextLine();
	                    System.out.println("Enter Updated String :");
	                    String newStr = sc.nextLine();
	                    trie.update(oldStr, newStr);
	                    System.out.println("Updated " + oldStr + " to " + newStr + " Succesfully");
	                    break;
	                case 5:
	                	System.out.println("Showing All data in the format : data => occurence");
	                	trie.showAll();
	                	break;
	                default:
	                	System.out.println("Please Enter Valid Choice");
	                	break;
	            }
	        }catch(Exception e) {System.out.println(e.getMessage());} 
            System.out.println();
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
    void update(String oldStr, String newStr)
    {
        delete(oldStr);
        insert(newStr);
    }

    void showAll()
    {
    	Stack<Character> s = new Stack<>();
    	showAll(root, s, ' ');
    }
    void showAll(Node curr, Stack<Character> s, char c)
    {
    	if(curr != root) s.push(c);
    	if(curr.terminating != 0)
    	{	
    		for(char i : s)
    			System.out.print(i);
			System.out.println(" => " + curr.terminating);
    	}
    	for(int i=0; i<26; i++)
    	{
    		if(curr.nodes[i] != null)
    			// showAll(curr[i], s+(char)(i + (int)'a'));
    			showAll(curr.nodes[i], s, (char)('a' + i));
    		
    		if(curr.nodesC[i] != null)
    			// showAll(curr[i], s+(char)(i + (int)'a'));
    			showAll(curr.nodesC[i], s, (char)('A' + i));
    	}

    	if(curr != root) s.pop();
    }
}

class Node
{
    Node nodes[] = new Node[26];
    Node nodesC[] = new Node[26];
    int terminating;
    Node next(char c)
    {
    	if(c >= 'A' && c <= 'Z')
    		return nodesC[c-'A'];
        return nodes[c-'a'];
    }
    void create(char c)
    {
    	if(c >= 'A' && c <= 'Z')
    		nodesC[c-'A'] = new Node();
    	else
        	nodes[c-'a'] = new Node();
    }
}