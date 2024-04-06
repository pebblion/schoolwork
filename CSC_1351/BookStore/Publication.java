//Student Name: Nathan Wandera
//LSU ID: 891973040

package BookStore;

public class Publication implements Comparable<Publication>{

    protected String genre;
    protected String title;
    protected String sorter;

    public Publication()
    {}

    public Publication(String title, String genre)
    {
        this.genre = genre;
        this.title = title;
        this.sorter = genre;
    }

    public String getInfo()
    {
        return title + ", " + genre;
    }

    public int compareTo(Publication other) {
        
        return sorter.compareTo(other.sorter);
    }



}