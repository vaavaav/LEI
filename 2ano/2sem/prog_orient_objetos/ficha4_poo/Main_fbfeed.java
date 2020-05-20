import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.*;
import java.io.*; 
import java.util.stream.*;

public class Main_fbfeed{
	public static void main(String[] args){

		FBFeed fbf = new FBFeed();

		ArrayList<FBPost> feed = new ArrayList<>();

		FBPost f1 = new FBPost("Pedro", "Hello World!");
		FBPost f2 = new FBPost("Jeff", "This is public announcement: ...");
		FBPost f3 = new FBPost("Bot", "Get your free iPhone 10: []click here]");
		FBPost f4 = new FBPost("Test", "This isn't a test.");

		feed.add(f1);
		feed.add(f2);
		feed.add(f3);
		feed.add(f4);

		fbf.setFeed(feed);

		fbf.comment(f4, "Are you listening to yourself?");
		fbf.comment(f4, "Liar!");
		fbf.comment(f4, "That's what all people say...");
		fbf.comment(f4, "->CLiCk HeRE<- to WIn An IPhonE 10 PLus");


		fbf.comment(f3, "uwu it's real guys! click it!");
		fbf.comment(f2, "You know you haven't said a thing... right?");

		fbf.like(f3);

		System.out.print(fbf);

		System.out.print("\n\n\n\nThe Top 5 Posts with most comments are: \n");
		Iterator i = fbf.top5Comments().iterator();
		while(i.hasNext()){
			System.out.print(fbf.getPost((int) i.next()));
			System.out.print("\n");
		}
		
	}
}