import javax.swing.JOptionPane;

class name_gui {
    public static void main(String[] args) {
        String name=JOptionPane.showInputDialog("Enter ur name");
        JOptionPane.showMessageDialog(null, "Hello "+name,"title", 0);
        String age=JOptionPane.showInputDialog("Enter ur age");
        JOptionPane.showMessageDialog(null, "You are "+age+" years old","title", 0);

    }
}
