
import 'dart:async';

import 'package:flutter/services.dart';

class DahuaPlayer {
  static const MethodChannel _channel =
      const MethodChannel('dahua_player');

  static Future<String> get platformVersion async {
    final String version = await _channel.invokeMethod('getPlatformVersion');
    return version;
  }
}
