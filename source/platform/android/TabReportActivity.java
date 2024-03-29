package com.ariasproj.platform.android;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Typeface;
import android.os.Build;
import android.os.Bundle;
import android.support.v4.app.NavUtils;
import android.view.MenuItem;
import android.widget.TextView;

public class TabReportActivity extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		
    // Get the message from the intent
    Intent intent = getIntent();
    String message = intent.getStringExtra(MainActivity.TAB_REPORT_MESSAGE);

    // Create the text view
    TextView textView = new TextView(this);
		Typeface externalFont = Typeface.createFromAsset(getAssets(), "fonts/Courier.ttf");
		textView.setTypeface(externalFont);
		
    //textView.setTextSize(40);
    textView.setText(message);
		//setContentView(R.layout.activity_tab_report);
    
		setContentView(textView);
		
    // Show the Up button in the action bar.
		setupActionBar();
	}

	/**
	 * default 
	 * Set up the {@link android.app.ActionBar}, if the API is available.
	 */
	@TargetApi(Build.VERSION_CODES.HONEYCOMB)
	private void setupActionBar() {
		if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB) {
			getActionBar().setDisplayHomeAsUpEnabled(true);
		}
	}


	/**
	 * default 
	 */
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
