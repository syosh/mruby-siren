#
# Array クラス拡張メソッド
#
class Array

  def to_v
    Vec::new self
  end

  def to(other)
    other.to_v - self.to_v
  end

  def from(other)
    self.to_v - other.to_v
  end

  def xyz
    self[0,3]
  end

  def xyz=(val)
    self[0,3] = val
  end

  def dist(other)
    (self.to_v - other.to_v).magnitude
  end

  def center(other)
    ((self.to_v + other.to_v) / 2.0).to_a
  end

  def equal?(other, lintol)
    dist(other) < lintol
  end

  def translate(t)
    (self.to_v + t.to_v).to_a
  end

  def translate!(t)
    val = translate(t)
    self.xyz = val.x, val.y, val.z
  end

  def trans(t)
    t.move_point self
  end

  def trans!(t)
    r = t.move_point self
    x = r.x, y = r.y, z = r.z
  end

  def x
    val = (self[0] ||= 0.0)
    if val.is_a?(Float)
      val
    elsif val.is_a?(Numeric)
      val.to_f
    else
      0.0
    end
  end

  def y
    val = (self[1] ||= 0.0)
    if val.is_a?(Float)
      val
    elsif val.is_a?(Numeric)
      val.to_f
    else
      0.0
    end
  end

  def z
    val = (self[2] ||= 0.0)
    if val.is_a?(Float)
      val
    elsif val.is_a?(Numeric)
      val.to_f
    else
      0.0
    end
  end

  def x=(val); self[0] = val end
  def y=(val); self[1] = val end
  def z=(val); self[2] = val end

end

