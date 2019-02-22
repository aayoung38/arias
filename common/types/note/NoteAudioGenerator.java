package com.ariasproj.common.types.note;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import com.ariasproj.common.AudioGenerator;
import com.ariasproj.common.types.instrument.guitar.GuitarNote;
import com.ariasproj.common.types.instrument.guitar.GuitarTab;

public class NoteAudioGenerator {
  private List<NoteObject> obj;
  private float beatsPerSecond;
  
  public NoteAudioGenerator(int beatsPerMinute) {
    this.beatsPerSecond =  (float) (60.0/ (float)beatsPerMinute);
    obj = new LinkedList<NoteObject>();
  }
  public void register(NoteObject note) {
    obj.add( note );
  }
  
  public void play() {
    System.out.println("*** Playing - ");
    for (NoteObject note : obj) {
      System.out.println("*** Playing - "+note.getValue().getBeats()*1000*beatsPerSecond);
      AudioGenerator.play2
        (note.getFrequency(),
            (int)(note.getValue().getBeats()*1000*beatsPerSecond));
      
      System.out.println("*** Playing - "+note.getValue().getBeats()*1000*beatsPerSecond);
    }
  }
  
  public void play(ArrayList<GuitarNote> tabs) {
      for (NoteObject note : tabs) {

        AudioGenerator.play2
          (note.getFrequency(),
             (int) (note.getValue().getBeats()*1000*beatsPerSecond));
        System.out.println("*** Playing - "+note.getFrequency()+" hz@"+note.getValue().getBeats()*1000*beatsPerSecond+"(ms)");
      
      }
    
  }
}
