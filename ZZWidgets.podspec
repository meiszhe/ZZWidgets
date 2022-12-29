#
# Be sure to run `pod lib lint ZZWidgets.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see https://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'ZZWidgets'
  s.version          = '1.0.1'
  s.summary          = 'A short description of ZZWidgets.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/meiszhe/ZZWidgets'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { 'meiszhe' => 'meiszhe1@163.com' }
  s.source           = { :git => 'https://github.com/meiszhe/ZZWidgets.git', :tag => s.version.to_s }

  s.ios.deployment_target = '10.0'

  s.source_files = 'ZZWidgets/Classes/**/*'
  s.public_header_files = 'ZZWidgets/Classes/**/*.h'

  s.subspec 'Pay' do |pay|
    pay.source_files = 'ZZWidgets/Classes/Pay/**/*'
    pay.public_header_files = 'ZZWidgets/Classes/Pay/**/*.h'
  end

  s.subspec 'Map' do |map|
    map.source_files = 'ZZWidgets/Classes/Map/**/*'
    map.public_header_files = 'ZZWidgets/Classes/Map/**/*.h'
  end
end
