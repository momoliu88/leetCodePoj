import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
public class LRUCache {
	private int capacity;
	private HashMap<Integer, Node> map = new HashMap<Integer, Node>();
	private Node head = new Node(-1, -1);
	private Node tail = new Node(-2, -2);

	public LRUCache(int capacity) {
		this.capacity = capacity;
		head.next = tail;
		tail.pre = head;
	}

	public int get(int key) {
		if (!map.containsKey(key))
			return -1;
		Node cur = map.get(key);
		cur.pre.next = cur.next;
		cur.next.pre = cur.pre;
		attach(cur);
		return cur.value;
	}

	public void set(int key, int value) {
		if (map.containsKey(key)) {
			Node cur = map.get(key);
			cur.value = value;
			cur.pre.next = cur.next;
			cur.next.pre = cur.pre;
			attach(cur);
		} else {
			if (map.size() == capacity)
				dettach();
			Node cur = new Node(key, value);
			attach(cur);
			map.put(key, cur);
		}
	}
	
	public void dettach(){
		Node last = tail.pre;
		last.pre.next = last.next;
		last.next.pre = last.pre;
		map.remove(last.key);
	}
	
	public void attach(Node cur){
		cur.next = head.next;
		cur.next.pre = cur;
		head.next = cur;
		cur.pre = head;
	}

	private class Node {
		public Node pre = null;
		public int key;
		public int value;
		public Node next = null;

		Node(int key, int value) {
			this.key = key;
			this.value = value;
		}
	}
}
