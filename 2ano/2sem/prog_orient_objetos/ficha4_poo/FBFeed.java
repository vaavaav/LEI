import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.*;
import java.io.*; 
import java.util.stream.*;

public class FBFeed{
	private ArrayList<FBPost> feed;

	public FBFeed(){
		this.feed = new ArrayList<>();
	}

	public FBFeed(ArrayList<FBPost> feed){
		this.feed = feed;
	}

	public void setFeed(ArrayList<FBPost> feed){
		this.feed = new ArrayList<>();
		for(FBPost f : feed)
			this.feed.add(f);
	}

	public ArrayList<FBPost> getFeed(){
		ArrayList<FBPost> feed = new ArrayList<>();
		for(FBPost f : this.feed)
			feed.add(f);
		return feed;
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		Iterator i = this.feed.iterator();
		while(i.hasNext()){
			sb.append(i.next());
			sb.append("\n\n\n\n");
		}
		return sb.toString();
	}

	public boolean equals(Object obj) {
        if(obj==this) return true;
        if(obj==null || obj.getClass() != this.getClass()) return false;
        FBFeed f = (FBFeed) obj;
        return f.getFeed().equals(this.feed);
    }


    public int nrPosts(String user){
    	return this.feed.stream().filter(x->x.getCreator().equals(user)).collect(Collectors.toList()).size();
    }

    public List<FBPost> postsOf(String user){
    	/*List<FBPost> r = new ArrayList<>();

    	for(FBPost f : this.feed)
    		if(f.getCreator().equals(user))
    			r.add(f);
    	return r;
    	*/
    	return this.feed.stream().filter(x->x.getCreator().equals(user)).collect(Collectors.toList());
    }

    public List<FBPost> postsOf(String user, LocalDateTime inicio, LocalDateTime fim){
    	List<FBPost> r = new ArrayList<>();
    	LocalDateTime aux;
    	for(FBPost f : this.feed)
    		if(f.getCreator().equals(user)){
    			aux = f.getDateTime();
    			if(!(aux.isBefore(inicio) && !(aux.isAfter(fim))))
    				r.add(f);
    		}
    	return r;
    }

    public FBPost getPost(int id){
    	FBPost r = null;
    	boolean f = false;
        if(id > 0){
    	for(int i = 0; i < this.feed.size() && !f; i++)
    		if(f = (this.feed.get(i).getId() == id))
    			r = this.feed.get(i);
        }
    	return r;
    }

    public void comment(FBPost post, String comentario){
    	post.comment(comentario);
    }

    public void comment(int postid, String comentario){
    	comment(this.getPost(postid), comentario);
    }

    public void like(FBPost post){
    	post.like();
    }

    public void like(int postid){
    	this.getPost(postid).like();
    }


    /* Iteradores internos*/
    public  List<Integer> top5Comments(){
    	List<Integer> r = new ArrayList<>(5); 
        List<Integer> n = new ArrayList<>(5);
        
        int i;
        boolean f = true;
        for(i = 0; i < this.feed.size() && f; i++)
            if(f = (r.size() < 5)){
                r.add(i, this.feed.get(i).getId());
                n.add(i, this.feed.get(i).getComments().size());
            }        
        for(; i < this.feed.size(); i++){
            int minIndex = n.indexOf(Collections.min(n));
            if(this.feed.get(i).getComments().size() > n.get(minIndex)){
                n.set(minIndex, this.feed.get(i).getComments().size());
                r.set(minIndex, this.feed.get(i).getId());
            }
        }

    	return r;
    }

    /* Iteradores Externos 
    public List<Integer> top5Comments(){
    	List<Integer> r = new ArrayList<>(5); 
    	List<Integer> r_sizes = new ArrayList<>(5);
    	return r;
    }
	*/
}