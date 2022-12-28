package com.example.android_progression_generator;

import java.awt.Color;
import java.awt.MenuItem;

import android.annotation.TargetApi;
import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.NavUtils;
import android.view.Display;
import android.widget.LinearLayout;
//import progression_generator_utilities.Guitar;
import com.ariasproj.common.MajorScaleManager;
import com.ariasproj.common.types.instrument.guitar.ScaleGuitar;
import com.ariasproj.common.ScaleManager;

public class GenerateMusicActivity extends Activity {
  
	private GuitarDrawView drawView;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		//super.onCreate(savedInstanceState);
		//setContentView(R.layout.activity_generate_music);
		// Show the Up button in the action bar.
		//setupActionBar();
		
    super.onCreate(savedInstanceState);

		setContentView(R.layout.activity_generate_music);
		
		Display display = getWindowManager().getDefaultDisplay(); 
		@SuppressWarnings("deprecation")
    int width = display.getWidth();  // deprecated
		//@SuppressWarnings("deprecation")
    //int height = display.getHeight();  // deprecated
		
		// Currently only support major keys
		ScaleManager major_manager = new MajorScaleManager(getIntent().getStringExtra("key_name"));
		System.out.println(getIntent().getStringExtra("key_name"));
		ScaleGuitar g = new Scale_Guitar(major_manager);
	  System.out.println(g);
		drawView = new GuitarDrawView(this, g, width, 1300 );
		drawView.setBackgroundColor(Color.GRAY);
		LinearLayout layout = (LinearLayout) findViewById(R.id.layout_guitar);
		
	  //Create a new instance of MyView...
	  
	  layout.addView(drawView);
		
	}

	/**
	 * Set up the {@link android.app.ActionBar}, if the API is available.
	 */
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	private void setupActionBar() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
			getActionBar().setDisplayHomeAsUpEnabled(true);
		}
	}

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		switch (item.getItemId()) {
		case android.R.id.home:
			// This ID represents the Home or Up button. In the case of this
			// activity, the Up button is shown. Use NavUtils to allow users
			// to navigate up one level in the application structure. For
			// more details, see the Navigation pattern on Android Design:
			//
			// http://developer.android.com/design/patterns/navigation.html#up-vs-back
			//
			NavUtils.navigateUpFromSameTask(this);
			return true;
		}
		return super.onOptionsItemSelected(item);
	}

}
