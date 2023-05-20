// ASSINGMENT NO : 8 Simple Animation 

#include <GL/glut.h>
float angle = 0.0f;
void update(int value)
{
    angle += 2.0f; // Update the angle for rotation
    if (angle > 360)
    {
        angle -= 360;
    }
    glutPostRedisplay(); // Call for redrawing the window
    // Update animation every 16 milliseconds (60 frames per second)
    glutTimerFunc(16, update, 0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);       // Clear the color buffer
    glPushMatrix();                     // Save the current matrix
    glRotatef(angle, 0.0f, 0.0f, 1.0f); // Rotate the object
    // Draw a square
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
    glPopMatrix(); // Restore the saved matrix
    glFlush();     // Flush the OpenGL pipeline
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);                       // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Set the display mode
    glutInitWindowSize(500, 500);                // Set the window size
    glutInitWindowPosition(100, 100);            // Set the window position
    glutCreateWindow("Simple Animation");        // Create the window
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);        // Set the background color
    glutDisplayFunc(display);                    // Register display callback function
    glutTimerFunc(0, update, 0);                 // Register update callback function
    glutMainLoop();                              // Enter the event-processing loop
    return 0;
}

