import java.util.*;

class Node
{
    int data;
    Node next, prev, nextLevel, prevLevel;
    Node(int data){
        this.data = data;
        this.next = this.prev = this.nextLevel = this.prevLevel = null;
    }
    public String toString(){
        return ""+data;
    }
}

class DLL
{
    Node start;
    DLL(){start = null;}
    void generateMultiLevelDoublyLinkedListFromArray(int arr[]){
        int size = arr.length;
        if(size == 0) return;
        start = new Node(arr[0]);
        Node t = start;
        Node currLevelStart = start;
        int i = 1;
        while(i < size){
            int data = arr[i];
            if(data == 0)
            {
                Node nextLevelStart = currLevelStart;
                i++;
                while(i<size){
                    data = arr[i];
                    if(data != 0) break;
                    if(nextLevelStart.next != null) nextLevelStart = nextLevelStart.next;
                    i++;
                }
                if(i == size) break;
                nextLevelStart.nextLevel = new Node(data);
                nextLevelStart.nextLevel.prevLevel = nextLevelStart;
                currLevelStart = nextLevelStart.nextLevel;
                t = currLevelStart;
            }
            else
            {
                Node curr = new Node(data);
                t.next = curr;
                curr.prev = t;
                t = curr;
            }
            i++;
        }
    }
    void flattern(Node node){
        if(node==null) return;
        System.out.print(node+" ");
        if(node.nextLevel!=null){
            flattern(node.nextLevel);
        }
        flattern(node.next);
    }
    void flattern(){flattern(this.start);}
}

class multiLevelDoublyLinkedList
{
    public static void main(String[] args) 
    {
        int arr[] = {10,20,30,40,50,0,0,60,70,80,0,90,100};
        for(int i : arr) System.out.print(i + " ");
        System.out.println();
        DLL list = new DLL();
        list.generateMultiLevelDoublyLinkedListFromArray(arr);
        list.flattern();
    }
}