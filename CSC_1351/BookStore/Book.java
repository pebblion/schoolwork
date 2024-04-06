//Student Name: Nathan Wandera
//LSU ID: 891973040

package BookStore;

public class Book extends Publication{

    private String author;

    public Book(String author, String title, String genre)
    {
        this.author = author;
        this.title = title;
        this.genre = genre;
        this.sorter = author;
    }

    @Override
    public String getInfo()
    {
        
        return title + ", " + genre + ". Written by " + author;
    }
}
