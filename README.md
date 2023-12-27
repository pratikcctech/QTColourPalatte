# QTColourPalatte

# OpenGL Window Project

A simple implementation of an OpenGL window  allowing dynamic shader loading and real-time curve visualization.

## Features

- Dynamic loading and watching of vertex and fragment shaders.
- Real-time update of curve colors.
- Visualization of curves in the OpenGL window.



1. **Launch the Application:**

   The OpenGL window will display default curves.

2. **Update Curve Colors:**
   Use the UI to dynamically update curve colors or load different shaders.

3. **curve Colour Function**

   ```
   void OpenGLWindow::selectCurveColor()
    {
        QColorDialog colorDialog(this);
        QColor selectedColor = colorDialog.getColor();
    
        if (selectedColor.isValid()) {
            // Set the selected color to the curves or store it for later use
            r = selectedColor.redF();
            g = selectedColor.greenF();
            b = selectedColor.blueF();
            emit dataUpdate();  // Trigger an update to redraw the curves with the new color
        }
    }
## Output

![Screenshot (121)](https://github.com/pratikcctech/QTColourPalatte/assets/149318512/3744ccc9-48a0-4bc4-b432-fef52aa4368c)

![Screenshot (122)](https://github.com/pratikcctech/QTColourPalatte/assets/149318512/27b15116-cdb9-49e7-9b58-0145ae54b7e5)



