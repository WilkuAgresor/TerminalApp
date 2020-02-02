import QtQuick 2.12


HouseOutlookForm {

    id: houseOutlook
    signal planeChanged(int selectedPlane)

    podworkoButton.onClicked:
    {
        parterImage.visible = false
        pietroImage.visible = false
        planeChanged(2)
    }

    pietroButton.onClicked:
    {
        parterImage.visible = false
        pietroImage.visible = true
        planeChanged(1)
    }
    parterButton.onClicked:
    {
        pietroImage.visible = false
        parterImage.visible = true
        planeChanged(0)
    }
}
