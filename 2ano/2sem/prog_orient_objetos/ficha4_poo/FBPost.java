import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.*;
import java.io.*; 

public class FBPost{

	private static int inc = 0;

	private int id;
	private String creator;
	private LocalDateTime dateTime;
	private String content;
	private int likes;
	private ArrayList<String> comments;

	public FBPost(String creator, String content){
		this.id = ++inc;
		this.creator = creator;
		this.dateTime = LocalDateTime.now();
		this.content = content;
		this.likes = 0;
		this.comments = new ArrayList<>();
	}

	public void setContent(String content){
		this.content = content;
	}

	public void comment(String comment){
		this.comments.add(comment);
	}

	public void like(){
		this.likes++;
	}

	public int getId(){
		return this.id;
	}

	public String getCreator(){
		return this.creator;
	}

	public LocalDateTime getDateTime(){
		return this.dateTime;
	}
	public String getContent(){
		return this.content;
	}

	public int getLikes(){
		return this.likes;
	}

	public ArrayList<String> getComments(){
		ArrayList<String> c = new ArrayList<>();
		for(String f : this.comments)
			c.add(f);
		return c;
	}

	public String toString(){
		StringBuilder sb = new StringBuilder();
		Iterator i = this.comments.iterator();
		sb.append("\"");
		sb.append(this.content);
		sb.append("\"\n Posted by: ");
		sb.append(this.creator);
		sb.append("        ");
		sb.append(this.dateTime);
		sb.append("\nLikes:[");
		sb.append(this.likes);
		sb.append("]");
		if(i.hasNext()){
			sb.append("\n\nComments:\n");
			while(i.hasNext()){
				sb.append("\n\t|\n\t| \"");
				sb.append(i.next());
				sb.append("\"");
			}
		}
		return sb.toString();
	}

	 public boolean equals(Object obj) {
        if(obj==this) return true;
        if(obj==null || obj.getClass() != this.getClass()) return false;
        FBPost f = (FBPost) obj;
        return f.getId() == this.id &&
              f.getCreator().equals(this.creator) && 
              f.getDateTime().equals(this.dateTime) &&
              f.getContent().equals(this.content) &&
              f.getComments().equals(this.comments);
    }

    public FBPost clone(){
    	FBPost f = new FBPost(this.creator, this.content);
    	f.id = this.getId();
    	f.dateTime = this.getDateTime();
    	f.likes = this.getLikes();
    	f.comments = this.getComments();
    	return f;
    }
}