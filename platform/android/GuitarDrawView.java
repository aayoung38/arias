package com.example.android_progression_generator;
import com.ariasproj.common.types.instrument.guitar.Guitar;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.View;
//import android.widget.ScrollView;

public class GuitarDrawView extends View {
    Paint paint = new Paint();

    private Guitar guitar;
    //private int width;
    private int height;

    private final int GUITAR_STRING_SPACING = 40;
    private final int GUITAR_STRING_START_X = 60;
    private int GUITAR_STRING_END_X;
    
    private final int GUITAR_FRET_SPACING = 55;
    private final int GUITAR_FRET_START_Y = GUITAR_STRING_START_X;
    private int GUITAR_FRET_END_Y;
    
    public GuitarDrawView(Context context) {
        super(context);
        paint.setColor(Color.BLACK);
    }
    
    public GuitarDrawView(Context context, Guitar guitar, int width, int height) {
        super(context);
        paint.setColor(Color.BLACK);
        
        this.guitar = guitar;
        //this.width = width;
        this.height = height;
        setVerticalScrollBarEnabled(true);
        setMinimumHeight(height);

        GUITAR_STRING_END_X = 
           GUITAR_STRING_START_X + (GUITAR_STRING_SPACING * (guitar.getNumStrings() - 1));
        
        GUITAR_FRET_END_Y = 
            GUITAR_FRET_START_Y + (GUITAR_FRET_SPACING * (guitar.getNumFrets() - 1));
        
    }

    @Override
    public void onDraw(Canvas canvas) {

    	   System.out.println(this.guitar);
         // set the string color
         paint.setColor(Color.RED);
         
         // draw the string to screen
         for(int i = GUITAR_STRING_START_X; i<=GUITAR_STRING_END_X; i = i+GUITAR_STRING_SPACING)
           canvas.drawLine(i, 0, i, this.height, paint);
            
         // draw frets to screen
         for(int i = GUITAR_FRET_START_Y, fret_num = 1; 
             i<=GUITAR_FRET_END_Y; 
             i = i+GUITAR_FRET_SPACING, fret_num++){
              
           // Do not draw fret if it exceeds the number of supported frets
           if (i < GUITAR_FRET_END_Y){
             paint.setColor(Color.BLACK);
             canvas.drawLine(GUITAR_FRET_START_Y, i+10, GUITAR_STRING_END_X, i+10, paint);
            
             paint.setColor(Color.BLACK);
             canvas.drawText(String.format("%2d",fret_num), 10, i+15, paint);
           }
         
         
           paint.setColor(Color.WHITE);
           for (int string_num = 0; string_num < guitar.getNumStrings(); string_num++){
                
             if (!guitar.getNote(string_num, fret_num-1).noteIsNull())
              	canvas.drawText("x", (GUITAR_STRING_START_X-4)+
                                    (string_num*GUITAR_STRING_SPACING), 
                                 i-GUITAR_FRET_SPACING+14, paint);
           } 
         }
            
    }

}
