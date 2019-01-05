#pragma once

#include <optional>

#include <QtWidgets/QWidget>

#include <mapex/geo_point.hpp>

class tile_widget final: public QWidget {
  Q_OBJECT
  Q_PROPERTY(int z_level READ z_level WRITE set_z_level)
public:
  tile_widget(geo_point center, int z_level, QWidget* parent = nullptr);

  void center_at(geo_point val);

  int z_level() const noexcept {return z_level_;}
  void set_z_level(int val) {z_level_ = val; update();}

protected:
  void paintEvent(QPaintEvent* event) override;
  void wheelEvent(QWheelEvent* event) override;
  void mousePressEvent(QMouseEvent* event) override;
  void mouseReleaseEvent(QMouseEvent* event) override;
  void mouseMoveEvent(QMouseEvent* event) override;

private:
  QPointF projected_center_;
  int z_level_ = 12;
  int wheel_accum_ = 0;
  std::optional<QPoint> last_mouse_move_pos_;
};
