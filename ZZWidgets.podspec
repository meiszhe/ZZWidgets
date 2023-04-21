#
# Be sure to run `pod lib lint ZZWidgets.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "ZZWidgets"
  s.version          = '1.1.0.5'
  s.summary          = 'A short description of ZZWidgets.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/meiszhe/ZZWidgets'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'meiszhe' => 'meiszhe1@163.com' }
  s.source           = { :git => 'https://github.com/meiszhe/ZZWidgets.git', :tag => s.version.to_s }

  s.platform     = :ios, "9.0"
  s.ios.deployment_target = "9.0"

  s.frameworks = "UIKit", "Foundation"

  # spec.library   = "iconv"
  # spec.libraries = "iconv", "xml2"
  s.libraries = "resolv", "c++"

  s.dependency 'SDWebImage', '5.14'

  s.vendored_frameworks = 'SDK/Core/BonreeCore.xcframework'

  #############################



  # s.subspec 'C' do |core|
  #   core.vendored_frameworks = 'SDK/Core/BonreeCore.xcframework'
  # end

  # s.subspec 'B' do |business|
  #   business.vendored_frameworks = 'SDK/Business/BonreeBusiness.xcframework'
  #   business.dependency 'ZZWidgets/C'
  # end

  # s.subspec 'R' do |rum|
  #   rum.vendored_frameworks = 'SDK/RUM/BonreeRUM.xcframework'
  #   rum.dependency 'ZZWidgets/C'
  #   rum.dependency 'ZZWidgets/B'
  # end

  # s.subspec 'L' do |log|
  #   log.vendored_frameworks = 'SDK/Log/BonreeLog.xcframework'
  #   log.dependency 'ZZWidgets/C'
  #   log.dependency 'ZZWidgets/B'
  #   log.version = '1.1.0.1'
  # end
  ########################

  # s.subspec 'Core' do |core|
  #   core.frameworks = 'Foundation'
  #   core.vendored_frameworks = 'SDK/Core/ZZKitCore.xcframework'
  # end

  # s.subspec 'Voice' do |voice_module|
  #   voice_module.vendored_frameworks = "SDK/Voice/ZZKitVoice.xcframework"
  #   voice_module.frameworks = 'Foundation'
  #   voice_module.dependency 'ZZWidgets/Core'
  # end

  # s.subspec 'RUM' do |rum_module|
  #   rum_module.vendored_frameworks = "SDK/RUM/ZZKitRUM.xcframework"
  #   rum_module.frameworks = 'Foundation'
  #   rum_module.dependency 'ZZWidgets/Core'
  # end

  # s.subspec 'Log' do |log_module|
  #   log_module.vendored_frameworks = "SDK/Log/ZZKitLog.xcframework"
  #   log_module.frameworks = 'Foundation'
  #   log_module.dependency 'ZZWidgets/Core'
  # end

end
