package com.ariasproj.common;

import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.IOException;

import javax.sound.sampled.AudioFileFormat;
import javax.sound.sampled.AudioFormat;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.DataLine;
import javax.sound.sampled.LineUnavailableException;
import javax.sound.sampled.SourceDataLine;

public class AudioGenerator {

  private static final int sampleRate = 44100;
  
	public AudioGenerator(){}
	
	private static float [] sampleNoteToPureSineWav
	  (double frequency, double seconds, float sampleRate)
	{
		
		// Sampled sine wave
		double amplitude = 0.8;
		System.out.println(seconds * sampleRate);
		float[] buffer = new float[(int) (seconds * sampleRate)];
		double twoPiF = 2 * Math.PI * frequency;
		for (int sample = 0; sample < buffer.length; sample++) {
		  double time = sample / sampleRate;
		  buffer[sample] = (float) ((float) amplitude * Math.sin(twoPiF * time));
		}
		
		return buffer;
		
	}
	
	private static float [] sampleNoteToComplexSineWav
	  (double frequency, double seconds, float sampleRate)
	{

		double amplitude0 = 0.8;
		double twoPiF0 = 2 * Math.PI * frequency;
		
		double frequency1 = 1.02 * frequency;
		double amplitude1 = 0.2;
		double twoPiF1 = 2 * Math.PI * frequency1;
		
		double frequency2 = 1.03 * frequency;
		double amplitude2 = 1.9;
		double twoPiF2 = 2 * Math.PI * frequency2;
		
		// Sampled sine wave
		float[] buffer = new float[(int) (seconds * sampleRate)];
		for (int sample = 0; sample < buffer.length; sample++) {
			double time = sample / sampleRate;
			double f0Component = amplitude0 * Math.sin(twoPiF0 * time);
			double f1Component = amplitude1 * Math.sin(twoPiF1 * time);
			double f2Component = amplitude2 * Math.sin(twoPiF2 * time);
			//buffer[sample] = (float) (f0Component + f1Component + f2Component);
			buffer[sample] = (float) (f2Component);
		}
		
		return buffer;
		
	}
	
	private static byte [] convertFloatsToBytes(float [] buffer){
		
		final byte[] byteBuffer = new byte[buffer.length * 2];
		int bufferIndex = 0;
		for (int i = 0; i < byteBuffer.length; i++) {
			final int x = (int) (buffer[bufferIndex++] * 32767.0);
			byteBuffer[i] = (byte) x;
			i++;
			byteBuffer[i] = (byte) (x >>> 8);
		}
		
		return byteBuffer;
	}
	
	private static AudioFormat writeBytesToWav(float sampleRate, byte [] byteBuffer, int buffer_length)
	{
				
		File out = new File("out.wav");
		if (out.exists()){
			out.delete();
			
			try {
	      out.createNewFile();
      } catch (IOException e) {
	      // TODO Auto-generated catch block
	      e.printStackTrace();
      }
			
		}
		
		boolean bigEndian = false;
		boolean signed = true;
		int bits = 16;
		int channels = 1;
		AudioFormat format = new AudioFormat(sampleRate, bits, channels, signed, bigEndian);
		AudioInputStream audioInputStream = 
		  new AudioInputStream(new ByteArrayInputStream(byteBuffer), format,buffer_length);
		try {
	    AudioSystem.write(audioInputStream, AudioFileFormat.Type.WAVE, out);
    } catch (IOException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
    }
		try {
	    audioInputStream.close();
    } catch (IOException e) {
	    // TODO Auto-generated catch block
	    e.printStackTrace();
    }
  	
		return format;
  }
  
	private static void playSound(AudioFormat format, byte [] byteBuffer)
	{
	
		DataLine.Info info = new DataLine.Info(SourceDataLine.class, format);
		SourceDataLine line = null;
		try {
			line = (SourceDataLine) AudioSystem.getLine(info);
		} catch (LineUnavailableException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			line.open(format);
		} catch (LineUnavailableException e) {
    // TODO Auto-generated catch block
			e.printStackTrace();
		}
		line.start();
		line.write(byteBuffer, 0, byteBuffer.length);
		line.close();
	}
	
	
	public static byte[] createSinWaveBuffer(double freq, int ms)
	{
	  int samples = (int)((ms * sampleRate) / 1000);
	  byte[] output = new byte[samples];
	  double period = (double)sampleRate /freq;
	  for (int i=0; i< output.length; i++) {
	    double angle = 2.0 * Math.PI * i / period;
	    output[i] = (byte)(Math.sin(angle) *127f);
	    
	  }
	  return output;
	}
	public static void play2(double frequency, int ms) {
	  final AudioFormat af = new AudioFormat(sampleRate, 8, 1, true, true);
	  SourceDataLine line = null;
    try {
      line = AudioSystem.getSourceDataLine(af);
    } catch (LineUnavailableException e1) {
      // TODO Auto-generated catch block
      e1.printStackTrace();
    }
	  try {
      line.open(af, sampleRate);
    } catch (LineUnavailableException e) {
      // TODO Auto-generated catch block
      e.printStackTrace();
    }
	  line.start();
	 // boolean forwardNotBlock = true;
	 // for (double freq=400; freq <=800;) {
	    byte[]toneBuffer = createSinWaveBuffer(frequency, ms);
	    int count = line.write(toneBuffer, 0,toneBuffer.length);
	    //if(forwardNotBlock) {
	    //  freq +=20;
	    //  forwardNotBlock = false;
	   // }
	   // else {
	   //   freq -= 10;
	   //   forwardNotBlock = true;
	   // }
	    
	  //}
	  line.drain();
	  line.close();
	  
	}
	
	public static void play(double frequency, double seconds)
	{
    boolean pureToneEnabled = true;
		
		// Get a sample for the note
		float[] toneBuffer = 
		    pureToneEnabled ?  
		      sampleNoteToPureSineWav(frequency, seconds, sampleRate) :
		      sampleNoteToComplexSineWav(frequency, seconds, sampleRate);
		
		// convert floats to bytes
		final byte[] toneByteBuffer = convertFloatsToBytes(toneBuffer);
		
		// write bytes to wave file
		AudioFormat cFormat = writeBytesToWav(sampleRate, toneByteBuffer, toneBuffer.length);
		
		//play sound
		playSound(cFormat, toneByteBuffer);
		
	}
	
}
