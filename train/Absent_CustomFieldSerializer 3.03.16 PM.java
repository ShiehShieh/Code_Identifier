

package com.google.common.base;

import com.google.common.annotations.GwtCompatible;
import com.google.gwt.user.client.rpc.SerializationStreamReader;
import com.google.gwt.user.client.rpc.SerializationStreamWriter;

@GwtCompatible
public class Absent_CustomFieldSerializer {
  public static void deserialize(SerializationStreamReader reader, Absent<?> instance) {}

  public static Absent<?> instantiate(SerializationStreamReader reader) {
    return Absent.INSTANCE;
  }

  public static void serialize(SerializationStreamWriter writer, Absent<?> instance) {}
}
