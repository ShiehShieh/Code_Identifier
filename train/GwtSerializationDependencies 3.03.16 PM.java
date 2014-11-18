
package com.google.common.base;

import com.google.common.annotations.GwtCompatible;

import java.util.Set;

import javax.annotation.Nullable;


@GwtCompatible
final class GwtSerializationDependencies {
  private GwtSerializationDependencies() {}

  static final class OptionalDependencies<T> extends Optional<T> {
    T value;

    OptionalDependencies() {
      super();
    }

    @Override public boolean isPresent() {
      throw new AssertionError();
    }

    @Override public T get() {
      throw new AssertionError();
    }

    @Override public T or(T defaultValue) {
      throw new AssertionError();
    }

    @Override public Optional<T> or(Optional<? extends T> secondChoice) {
      throw new AssertionError();
    }

    @Override public T or(Supplier<? extends T> supplier) {
      throw new AssertionError();
    }

    @Override public T orNull() {
      throw new AssertionError();
    }

    @Override public Set<T> asSet() {
      throw new AssertionError();
    }

    @Override public <V> Optional<V> transform(
        Function<? super T, V> function) {
      throw new AssertionError();
    }

    @Override public boolean equals(@Nullable Object object) {
      throw new AssertionError();
    }

    @Override public int hashCode() {
      throw new AssertionError();
    }

    @Override public String toString() {
      throw new AssertionError();
    }
  }
}
