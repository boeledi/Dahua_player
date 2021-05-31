#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html.
# Run `pod lib lint dahua_player.podspec` to validate before publishing.
#
Pod::Spec.new do |s|
  s.name             = 'dahua_player'
  s.version          = '0.0.1'
  s.summary          = 'A new flutter plugin project.'
  s.description      = <<-DESC
A new flutter plugin project.
                       DESC
  s.homepage         = 'http://www.didierboelens.com'
  s.license          = { :file => '../LICENSE' }
  s.author           = { 'Your Company' => 'email@example.com' }
  s.source           = { :path => '.' }

  s.libraries = 'bz2','iconv','c++'
  s.static_framework = true

  s.source_files = 'Classes/**/*'
  s.public_header_files = 'Classes/**/*.h', 'include/*.h'
  s.private_header_files = 'include/*.h'
  
  s.dependency 'Flutter'
  s.platform = :ios, '12.1'

  s.vendored_libraries = 'lib/*.a'
  s.frameworks = 'AudioToolbox','CoreVideo','CoreMedia','CoreGraphics','MediaPlayer','VideoToolbox'
  
end
