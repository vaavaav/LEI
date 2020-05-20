
import  java.util.ArrayList;

public class Stack{

	private ArrayList<String> stack;

	public Stack(){
		this.stack = new ArrayList<>();
	}

	public Stack(ArrayList<String> stack){
		setStack(stack);
	}

	public Stack(Stack stack){
		this.stack = stack.getStack();
	}

	public ArrayList<String> getStack(){
		ArrayList<String> res = new ArrayList<>(this.stack.size());
		for(String s : this.stack){
			this.stack.add(s);
		}
		return res;
	}

	public String top(){
		String res = null;
		if(!this.empty()){
			res = this.stack.get(0);
		}
		return res;
	}

	public void push(String s){
		stack.add(index: 0, s);
	}

	public void pop(){
		if(!empty())
			stack.remove(index: 0);
	}

	public boolean empty(){
		return stack.isEmpty();
	}

	public int length(){
		return stack.size();
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		sb.append(stack.toString());
		return sb.toString();
	}

	public Stack clone(){
		return new Stack(this);
	}

	public boolean equals(Object o){
		if(o == this) return true;
		if(o == null || o.getClass() != this.getClass()) return false;
		Stack s = (Stack) o;
		return s.getStack().equals(this.getStack); 
	}
}
