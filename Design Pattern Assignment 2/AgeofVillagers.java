public class AgeofVillagers {
    public static void main(String[] args) {
        shape greencircle = new shape("Circle","Green");
        shape brownline = new shape("Line","Brown");

        shape tree = new shape("Tree","Green");
        tree.add(greencircle);
        tree.add(brownline);

        shape whiteplane = new shape("Plane","White");
        shape whitecube = new shape("Cube","White");
        whitecube.add(whiteplane);

        shape graytriangle = new shape("Triangle","Gray");
        shape graypyramid = new shape("Pyramid","Gray");
        graypyramid.add(graytriangle);

        shape house = new shape("House","Gray-White");
        house.add(whitecube);
        house.add(graypyramid);

        shape bluerectangle = new shape("Rectangle","Blue");
        shape blackhalfcircle = new shape("Half-Circle","Black");
        shape pound = new shape("Pound","Blue");
        pound.add(bluerectangle);
        pound.add(blackhalfcircle);

        shape village = new shape("Village","Random");
        village.add(house);
        village.add(tree);
        village.add(pound);

        System.out.println(village);
        village.printContains();

        System.out.println(house);
        house.printContains();
    }
}
