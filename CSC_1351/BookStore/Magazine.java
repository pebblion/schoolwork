//Student Name: Nathan Wandera
//LSU ID: 891973040

package BookStore;

public class Magazine extends Publication {
    
    private String publisher;

    public Magazine(String publisher, String title, String genre)
    {
        this.publisher = publisher;
        this.title = title;
        this.genre = genre;
        this.sorter = publisher;
    }

    @Override
    public String getInfo()
    {
        return title + ", " + genre + ". Published by " + publisher;
    }



}
